#include "Header.h"

int main(void)
{
	//For the rand() function
	srand(time(NULL));
	//Variables of doubles
	double wager_amount = 0.0, bank_balance = 0.0, present_balance = 0.0;
	//Variables of integers
	int dice_value_1 = 0, dice_value_2 = 0, dice_sum = 0, point_value = 0, check = 0, add_or_subtract = 0, start = 0, counter = 0;
	//Printing Game Rules
	print_game_rules();

	//Adding Bank Balance (Will Be Changed In Scope Of Loop)
	bank_balance = get_bank_balance();
	printf("Current Bank Balance: %lf\n", bank_balance);

	//Setting a do-while loop for when start == 1. If start isn't one the loop isn't cycled through again
	do {
		//Setting a do-while loop for the wager amount. "Commencing New Game" is to see when new games start
		do {
			//Grab Wager Amount At Start Of Game
			wager_amount = get_wager_amount();
			//printf("Commencing New Game...\n");
		} while (check_wager_amount(wager_amount, bank_balance) != 1);

		//Setting values of dice to a newly recalled roll_die() function
		dice_value_1 = roll_die();
		printf("Dice #1: %d\n", dice_value_1);
		dice_value_2 = roll_die();
		printf("Dice #2: %d\n", dice_value_2);
		dice_sum = calculate_sum_dice(dice_value_1, dice_value_2);
		printf("Dice Sum: %d\n", dice_sum);
		add_or_subtract = is_win_loss_or_point(dice_sum);

		//When add_or_subtract is 1 OR 0 (WIN OR LOSS) then we set add_or_subtract to is_win_loss_or_point to check values
		if (add_or_subtract == 1 || 0) {
			add_or_subtract = is_win_loss_or_point(dice_sum);
		}
		else if (add_or_subtract == -1) { //This is when the point is returned in other words when (-1) is returned
			point_value = dice_sum; //Setting the point value equal to the some of the dice
			printf("The Point Value Is %d! Good Luck\n", point_value); //Announcing the point
			add_or_subtract = is_point_loss_neither(dice_sum, point_value); //Setting this equal to grab point value result
		}

	//Present Balance Is Equal To The Original Bank Balance
	present_balance = bank_balance;
	
	//Setting The Newly Adjusted Bank Balance
	bank_balance = adjust_bank_balance(bank_balance, wager_amount, add_or_subtract);
	//Using the chatter_messages with the conditionals from the equations.c
	chatter_messages(counter, add_or_subtract, present_balance, bank_balance);

	//Prompting the user for whether or not they want to continue
	printf("Would You Like To Keep Playing? Press '1' For Yes, To Leave Press Anything\n");
	scanf("%d", &start);

	//Adding one value to the counter every time a game is played, this is for the chatter_messages sake
	++counter;
	//When start == 1 the game will start again
	}while (start == 1);
}
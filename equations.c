#include "header.h"

//Printing game rules with a a simply printf and return
void print_game_rules(void)
{
	printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots. After the dive have come to rest, the sum of the spots on the two upward faces is calculated. If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called craps),  the player loses (i.e. the house wins). If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point. To win, you must continue rolling the dive until you make your point. The player loses by rolling a 7 before making the point.\n");

	return;
}

//Prompting and scanning to get a bank_balance
double get_bank_balance(void)
{
	double bank_balance = 0;

	printf("\nHow much money do you want to start with? ");

	scanf("%lf", &bank_balance);

	return bank_balance;
}

//Prompting and scanning to get a wager_amount
double get_wager_amount(void)
{
	double wager_amount = 0;

	printf("\nHow much would you like to wager: ");

	scanf("%lf", &wager_amount);

	return wager_amount;
}

//Getting a wager amount that is less than or equal to the bank balance (negative integers don't work)
int check_wager_amount(double wager_amount, double bank_balance)
{
	if (wager_amount <= bank_balance) {
		if (wager_amount > 0) {
			return 1;
		}
		else if (wager_amount < 0) {
			printf("Wager Amount Cannot Be Negative");
		}
	}
	return 0;
}

//Collecting dice values (reference: PA4 Starter Code, September 27th
int roll_die(void)
{
	int dice = 0;
	dice = rand() % 6 + 1;

	return dice;
}

//Simply adding the dice together, returning a variable for aesthetics
int calculate_sum_dice(int die1_value, int die2_value)
{
	return die1_value + die2_value;
}

//Finding sum of dice and returning what is necessary
int is_win_loss_or_point(int sum_dice) 
{
	//Winning Conditional
	if (sum_dice == 7 || sum_dice == 11) {
		return 1;
	}
	//Losing Conditional
	else if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {
		return 0;
	}
	//The Point Conditional
	else {
		return -1;
	}
}

int is_point_loss_neither(int sum_dice, int point_value) 
{
	do
	{
		int die1, die2;
		die1 = roll_die();
		die2 = roll_die();
		point_value = die1 + die2;
		//Tells the user what they rolled and what they need to role
		printf("You rolled a %d and you need a %d for the point!\n", point_value, sum_dice);
		if (point_value == sum_dice)
		{
			return 1;
		}
	} while (point_value != 7);  {
		return 0;
	}
	return -1;
}


//Add and subtracting wagers
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {
	//double bank_balance, double wager_amount, int add_or_subtract
	if (add_or_subtract == 1) {
		bank_balance = bank_balance + wager_amount;
	} else if (add_or_subtract == 0) {
		bank_balance = bank_balance - wager_amount;
	}
	//bank balance return as stated in the directions
	return bank_balance;
}

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {

	//When number of rolls is zero (or the first roll) then it will tell them
	if(number_rolls == 0) {
		printf("That was your first roll! Keep it up!\n");
	}
	//When number of rolls is not 1 then it will tell them how many games they are at
	else if (number_rolls != 0) {
		printf("You have played %d times! Keep it up!\n", number_rolls);
	}
	
	//Print telling the user what their current balanace is
	printf("Your new bank balance is %lf and your old balance was %lf\n", current_bank_balance, initial_bank_balance);

	//As stated in the directions when win_loss_neither is equal to 1 the user wins
	if (win_loss_neither == 1) {
		printf("Round Win, Congratulations\n");
	} 
	//Also as stated when win_loss_neither is equal to 0 the user loses
	else if (win_loss_neither == 0) {
		printf("Round Loss, Better luck next time!\n");
	}
	//If win_loss_neither were equal to -1 it would be the point. That would be returning 1 or 0 anyway after finding the point.
}
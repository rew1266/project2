//------------------------------------------------------------
// Purpose: To implement an interactive horoscope generator.  
//          The user will enter their birthdate and answer a few
//          questions, and the program will print some advice.
//
// Author:  John Gauch - Created skeleton program.
// Author:  Russell Wacaster - Finished implementation of program.
//------------------------------------------------------------
#include <cstdlib>
#include <iostream>
using namespace std;

//------------------------------------------------------------
// Purpose: To prompt the user to enter their birthdate.
// Input:   None.
// Output:  The user's birth year, month, day.
//------------------------------------------------------------
void GetBirthDate(int & year, string & month, int & day)
{
   // Prompt user for birth year
   year = 0;
   while ((year < 1900) || (year > 2019))
   {
      cout << "Enter the year you were born [1900..2019]: ";
      cin >> year;
   }

   // Prompt user for birth month
   month = "";
   while (month != "Jan" && month != "Feb" && month != "Mar" && 
          month != "Apr" && month != "May" && month != "Jun" && 
          month != "Jul" && month != "Aug" && month != "Sep" && 
          month != "Oct" && month != "Nov" && month != "Dec")
   {
      cout << "Enter the month you were born [Jan..Dec]: ";
      cin >> month;
   }

   // Prompt user for birth day
   day = 0;
   while ((day < 1) || (day > 31))
   {
      cout << "Enter the day you were born [1..31]: ";
      cin >> day;
   }
}

//------------------------------------------------------------
// Purpose: To calculate the user's karma.
// Input:   None.
// Output:  The user's karma score.
//------------------------------------------------------------
int GetKarma()
{
   int answer = 0;
   int karma = 0;
   cout << "How many people have you said hello to today? ";
   cin >> answer;
   
   // Silly karma calculation
   if (answer <= 0)
      return 0;
   else if (answer == 42)
      return 100;
   else 
      return (answer / 2) + (random() % 5);
}

//------------------------------------------------------------
// Purpose: Calculate the user's astrological sign.
// Input:   The user's birth month, day.
// Output:  The user's astrological sign.
//------------------------------------------------------------
string GetSign(const string month, const int day)
{
   if ((month == "Mar" && day >= 21) || (month == "Apr" && day <= 20))
      return "Aries";
   if ((month == "Apr" && day >= 21) || (month == "May" && day <= 21))
      return "Taurus";
   if ((month == "May" && day >= 22) || (month == "Jun" && day <= 21))
      return "Gemini";
   if ((month == "Jun" && day >= 22) || (month == "Jul" && day <= 22))
      return "Cancer";
   if ((month == "Jul" && day >= 23) || (month == "Aug" && day <= 22))
      return "Leo";
   if ((month == "Aug" && day >= 23) || (month == "Sep" && day <= 23))
      return "Virgo";
   if ((month == "Sep" && day >= 24) || (month == "Oct" && day <= 23))
      return "Libra";
   if ((month == "Oct" && day >= 24) || (month == "Nov" && day <= 22))
      return "Scorpio";
   if ((month == "Nov" && day >= 23) || (month == "Dec" && day <= 21))
      return "Sagittarius";
   if ((month == "Dec" && day >= 22) || (month == "Jan" && day <= 20))
      return "Capricorn";
   if ((month == "Jan" && day >= 21) || (month == "Feb" && day <= 19))
      return "Aquarius";
   if ((month == "Feb" && day >= 20) || (month == "Mar" && day <= 20))
      return "Pisces";
   return "";
}

//------------------------------------------------------------
// Purpose: Romance prediction
// Input:   The user's karma score.
// Output:  Prediction message.
//------------------------------------------------------------
string Romance(const int karma)
{
   int choice = (karma * 17) % 5;
   string message = "";
   switch(choice)
   {
   case 0:
      message = "Maybe your date would like to see a romantic comedy?";
      break;
   case 1:
      message = "I think it is singles night at the local pub.";
      break;
   case 2:
      message = "You should sit by the fire and read a good romance novel.";
      break;
   case 3:
      message = "Searching online for the perfect date seldom works.";
      break;
   case 4:
      message = "Love is not in the air tonight, time to play video games.";
      break;
   default:
      message = "Romance prediction is impossible.";
      break;
   }
   return message;
}

//------------------------------------------------------------
// Purpose: Money prediction
// Input:   The user's birth year.
// Output:  Prediction message.
//------------------------------------------------------------
void Money(const int year, string & message)
{
   int choice = (2019 - year) / 10;
   switch(choice)
   {
   case 0:
      message = "Ask your parents for their spare change.";
      break;
   case 1:
      message = "This is a good time to ask your parents for a bigger allowance.";
      break;
   case 2:
      message = "You can save more money by buying less beer.";
      break;
   case 3:
      message = "Try to save a little extra for a down payment on a house.";
      break;
   case 4:
      message = "Yikes, your children's tuition bills are due soon.";
      break;
   default:
      message = "Money prediction is impossible.";
      break;
   }
}

//------------------------------------------------------------
// Purpose: Job prediction
// Input:   The user's birth day and karma score.
// Output:  Prediction message.
//------------------------------------------------------------
string Job(const int day, const int karma)
{
   string message = "";
   if ((day < 15) && (karma > 5))
      message = "Your boss looks generous today, time to ask for a raise.";
   else if ((day > 15) && (karma < 5))
      message = "Prepare for bad news, your company profits are down.";
   else if ((day == 15) && (karma == 5))
      message = "Bad news, your company is declaring bankruptcy.";
   else if (karma > day)
      message = "Great news, your company just went public!";
   else if (karma <= day)
      message = "It looks like a chance for some overtime.";
   else
      message = "Job prediction is impossible.";
   return message;
}

//------------------------------------------------------------
// Purpose: Family prediction
// Input:   Month and karma 
// Output:  Prediction message.
//------------------------------------------------------------
string Family(const string month, const int karma)
{
    string message = "";
   if ((month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov") && (karma > 5))
      message = "Exciting news! Your family is proud of your hard work and will be treating you to a nice dinner soon.";
   else if ((month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov") && (karma < 5))
      message = "Bad news, your family claims you're an alcoholic and is cutting your funds.";
   else if ((month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov") && (karma == 5))
      message = "Be ready to make some food. You're family is visiting soon.";
   else if ((month == "Mar" || month == "May" || month == "Jun" || month == "Dec") && (karma > 5))
      message = "Soon your family will be sending you a healthy check in the mail.";
   else if ((month == "Mar" || month == "May" || month == "Jun" || month == "Dec") && (karma < 5))
      message = "Your family is moving soon and will be needing your help. Clear up your schedule.";
   else if ((month == "Mar" || month == "May" || month == "Jun" || month == "Dec") && (karma == 5))
      message = "Your family is upset that you haven't visited in a while. They now claim you don't love them.";
   else if ((month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep") && (karma > 5))
      message = "Lucky for you, your family will be paying a few of your upcoming bills.";
   else if ((month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep") && (karma < 5))
      message = "Your family is still proud of you but they hope you'll put in more effort in your work.";
   else if ((month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep") && (karma == 5))
      message = "Your family has run onto rough times and really needs you to help pay bills.";
    else
      message = "Family prediction is impossible.";
   return message;
}

//------------------------------------------------------------
// Purpose: Health prediction
// Input:   Day and karma 
// Output:  Prediction message.
//------------------------------------------------------------
// ADD FUNCTION HERE
string Health(const int day, const int karma)
{
    string message = "";
    if ((day >= 1 && day <= 11) && (karma > 5))
        message = "Your health shall be good for at the least the next month.";
    else if ((day >= 1 && day <= 11) && (karma < 5))
        message = "It appears that your health is declining.";
    else if ((day >= 1 && day <= 11) && (karma == 5))
        message = "Your health may flutuate randomly in the near future.";
    else if ((day >= 12 && day <= 22) && (karma > 5))
        message = "Good news for you, your health seems to be in tip top shape.";
    else if ((day >= 12 && day <= 22) && (karma < 5))
        message = "Allergy season is coming and it's gonna hit you like a truck.";
    else if ((day >= 12 && day <= 22) && (karma == 5))
        message = "Your health is going to stay stable but you may want to take some allergy pills.";
    else if ((day >= 23 && day <= 31) && (karma > 5))
        message = "Good news! You appear to be healthy as ever.";
    else if ((day >= 23 && day <= 31) && (karma < 5))
        message = "You have a serious health issue in your near future.";
    else if ((day >= 23 && day <= 31) && (karma == 5))
        message = "Keep up the lifestyle you're living and your health will remain great.";
    else
        message = "Health prediction is impossible.";
    return message;
}

//------------------------------------------------------------
// Purpose: Silly prediction
// Input:   Day, month, and karma 
// Output:  Prediction message.
//------------------------------------------------------------
// ADD FUNCTION HERE
string Silly(const int day, const string month, const int karma)
{
    string message = "";
    if ((day >= 1 && day <= 11) && (karma > 5) && (month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov"))
        message = "You should see a dog sometime this week and he will love you.";
    else if ((day >= 1 && day <= 11) && (karma < 5) && (month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov"))
        message = "A black cat will cross your path.";
    else if ((day >= 1 && day <= 11) && (karma == 5) && (month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov"))
        message = "Your car might give you some issues.";
    else if ((day >= 12 && day <= 22) && (karma > 5) && (month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov"))
        message = "You will stumble across $20.";
    else if ((day >= 12 && day <= 22) && (karma < 5) && (month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov"))
        message = "You will lose $20.";
    else if ((day >= 12 && day <= 22) && (karma == 5) && (month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov"))
        message = "You will find $20 but then have to spend it on a random bill.";
    else if ((day >= 23 && day <= 31) && (karma > 5) && (month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov"))
        message = "You might be lucky enough to win the lottery.";
    else if ((day >= 23 && day <= 31) && (karma < 5) && (month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov"))
        message = "Your in laws are coming to town soon. Better hide.";
    else if ((day >= 23 && day <= 31) && (karma == 5) && (month == "Jan" || month == "Jul" || month == "Jun" || month == "Nov"))
        message = "Your significant other will ask for something special.";
    else if ((day >= 1 && day <= 11) && (karma > 5) && (month == "Mar" || month == "May" || month == "Jun" || month == "Dec"))
        message = "Your boss will go easy on you for a while.";
    else if ((day >= 1 && day <= 11) && (karma < 5) && (month == "Mar" || month == "May" || month == "Jun" || month == "Dec"))
        message = "Your boss is going to blame everything on you.";
    else if ((day >= 1 && day <= 11) && (karma == 5) && (month == "Mar" || month == "May" || month == "Jun" || month == "Dec"))
        message = "Your boss will be upset with you for no reason.";
    else if ((day >= 12 && day <= 22) && (karma > 5) && (month == "Mar" || month == "May" || month == "Jun" || month == "Dec"))
        message = "You will recieve something special in the mail.";
    else if ((day >= 12 && day <= 22) && (karma < 5) && (month == "Mar" || month == "May" || month == "Jun" || month == "Dec"))
        message = "Your boss will offer you a full week of paid vacation.";
    else if ((day >= 12 && day <= 22) && (karma == 5) && (month == "Mar" || month == "May" || month == "Jun" || month == "Dec"))
        message = "Your boss will take away your vacation time for no reason.";
    else if ((day >= 23 && day <= 31) && (karma > 5) && (month == "Mar" || month == "May" || month == "Jun" || month == "Dec"))
        message = "I'm running out of ideas so I'll say you're just gonna have a good day.";
    else if ((day >= 23 && day <= 31) && (karma < 5) && (month == "Mar" || month == "May" || month == "Jun" || month == "Dec"))
        message = "Sorry for you but I think your day is going to suck.";
    else if ((day >= 23 && day <= 31) && (karma == 5) && (month == "Mar" || month == "May" || month == "Jun" || month == "Dec"))
        message = "You're going to wake up late someday soon.";
    else if ((day >= 1 && day <= 11) && (karma > 5) && (month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep"))
        message = "I think you'll get something amazing soon.";
    else if ((day >= 1 && day <= 11) && (karma < 5) && (month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep"))
        message = "You'll suddenly have a change of mind soon.";
    else if ((day >= 1 && day <= 11) && (karma == 5) && (month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep"))
        message = "You're going to get a new pet soon.";
    else if ((day >= 12 && day <= 22) && (karma > 5) && (month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep"))
        message = "This is getting old. Just have a good day.";
    else if ((day >= 12 && day <= 22) && (karma < 5) && (month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep"))
        message = "It appears that your upcoming week is going to be terrible.";
    else if ((day >= 12 && day <= 22) && (karma == 5) && (month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep"))
        message = "You're going to do just OK on your upcoming assingments.";
    else if ((day >= 23 && day <= 31) && (karma > 5) && (month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep"))
        message = "You're going to discover a new way to make cash fast.";
    else if ((day >= 23 && day <= 31) && (karma < 5) && (month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep"))
        message = "Be cautious of everything as you're going to be scammed soon.";
    else if ((day >= 23 && day <= 31) && (karma == 5) && (month == "Feb" || month == "Apr" || month == "Oct" || month == "Sep"))
        message = "I'm finally done with horoscopes just have a great day.";
    else
        message = "Silly prediction is impossible.";
    return message;
}

//------------------------------------------------------------
// Purpose: Print user's horoscope.
// Input:   The user's birth year, month, day, karma.
// Output:  None.
//------------------------------------------------------------
void PrintHoroscope(const int year, const string month, 
   const int day, const int karma, string message)
{
   // Print user's sign
   cout << GetSign(month, day) << endl;

   // Print romance prediction
   cout << Romance(karma);

   // Print money prediction
   cout << message << endl;

   // Print job prediction
   cout << Job(day, karma) << endl;

   // Print family prediction
   cout << Family(month,karma) << endl;

   // Print health prediction
   cout << Health(day,karma) << endl;
   
   // Print silly prediction
   cout << Silly(day, month, karma) << endl;
}

//------------------------------------------------------------
// Purpose: The main program.
// Input:   None.
// Output:  None.
//------------------------------------------------------------
int main()
{
   // Initialize random number generator
   srandom(time(NULL));

   // Local variables
   int year = 0;
   int day = 0;
   string month = "";
   string message = "";
   

   // Get user's birthday
   GetBirthDate(year, month, day);
   

   // Get user's karma points 
   int karma = GetKarma();

   // Print horoscope
   PrintHoroscope(year, month, day, karma, message);

   
   return 0;
}


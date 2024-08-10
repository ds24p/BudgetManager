

class BudgetMainApp
{
    UserManager userManager;
    //BudgetManager *budgetManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

public:
    //BudgetMainApp (string userFileName, string incomeFileName, string expenseFileName);
    bool isUserLoggedIn();
    void registerUser();
    void loginUser();
    void changeUserPassword();
    void logoutUser();
    //void addIncome();
   // void addExpense();
   // void showCurrentMonthBalance();
   // void showPreviousMonthBalance();
   // void showCustomPeriodBalance();

};

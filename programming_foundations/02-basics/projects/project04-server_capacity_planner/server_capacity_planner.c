#include <stdio.h>

int main() 
{
    //declare the variables needed
    /*
    when we declare the variables, we are preparing space in the memory to store the values we
    enter when we initialize the variables.
    since the values we need to place in them have to be entered by user input, we will not init
    them right now.
    */
    int number_of_servers_needed;
    int cpu_cores_per_server;
    int RAM_per_server_in_GB;
    double montly_cost_per_server;
    char report_author_name[50];

    //taking user input
    /*
    the difference between the 'printf()' and 'scanf()' function is:

    -printf() will copy the values of the variables from the memory address and prints them
     to the screen, it does not change the original values at the specific memory address.

    -scanf() will use the actual memory address, it will take the user's inputed data and place
     it directly in the memory address... we do this by using the '&' keyword before the name of
     the variable to point towards its memory address.
     > we do not need to do this for strings (arrays of chars) as the variable_name[X] is already
       pointing towards the memory address, so whatever value is put in by the user gets auto placed
       into the memory address. 

    */
    printf("enter the number of servers needed: ");
    scanf("%d", &number_of_servers_needed);

    printf("enter the number of CPU cores per server: ");
    scanf("%d", &cpu_cores_per_server);

    printf("how much RAM (in GBs) per server?: ");
    scanf("%d", &RAM_per_server_in_GB);

    printf("what will the monthly costs of running ONE server be?: ");
    scanf("%lf", &montly_cost_per_server);

    printf("what is the name of the person writing this report (your first name)?: ");
    scanf("%s", report_author_name);

    //the calculations
    int total_cores = number_of_servers_needed * cpu_cores_per_server;
    int total_ram_in_GB = number_of_servers_needed * RAM_per_server_in_GB;
    //we use the 'long long int' data type because this calculation's result is too large for the regular int
    //data type
    long long int total_ram_in_bytes = (long long int)total_ram_in_GB * 1073741824;
    double total_monthly_running_costs = number_of_servers_needed * montly_cost_per_server; 

    //the final print statement... tried to make it look nice :)
    printf("--- QUOTE ---\n");
    printf("Report Author:         \t %s\n", report_author_name);
    printf("Total Cores:           \t %d\n", total_cores);
    printf("Total RAM (in GBs):    \t %d\n", total_ram_in_GB);
    printf("Exact RAM in Bytes:    \t %lld\n", total_ram_in_bytes);
    printf("Total Cost/Month($USD):\t %.2lf\n", total_monthly_running_costs);


    return 0;
}
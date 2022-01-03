#include <iostream>
#include <climits> // limits for integral types
#include <cmath> // for exponent

using namespace std;

// This function will return the number of occurrence of a digit in a number.
int occurrence_counting(unsigned int number_to_process, unsigned int digit)
{
    int occurrence = 0;
    while (number_to_process > 0)
    {
        if (number_to_process % 10 == digit)
            occurrence += 1;
        number_to_process /= 10;
    }

    return occurrence;

}

// This function will return the index of a digit at its n-th occurrence (order) in a number.
// Index starts with 0 from left to right.
// This function returns -1 when the occurrence of the digit is smaller than "order".
int index_finding(unsigned int number_to_process, unsigned int digit, unsigned int order)
{
    // You may count the number of digits of number_to_process first
    // then you can extract the digit at position i as the remainder by dividing appropriate number
    int number_of_digits = 0;
    int index = 0;
    int result;
    int order_count = 0;
    
    int digit_count = number_to_process;     
    while (digit_count != 0)
    {
        digit_count /= 10;
        number_of_digits += 1;
    }
    
    int power = number_of_digits - 1;

    while (index < number_of_digits)
    {
        result = number_to_process / pow(10, power);
        result = result % 10;
        //cout << result << endl;
        if (result == digit)
        {
            order_count += 1;
            if (order_count == order)
                break;
        }
        index += 1;
        power -= 1;
    }

    if (order > order_count || order <= 0)
        return -1;
    else
        return index;
}

// This function will print all digits in a number with the occurrence larger than a threshold.
// Printed digits should be in an ascending order. 
// Prints nothing if none of the digits occurs more than the thresold.
// You may call the above functions in this function.
void filtering_by_occurrence(unsigned int number_to_process, unsigned int occurrence_threshold)
{
    int number_of_digits = 0;
    int result;
    int digits[10] = {};    // 0에서 9까지의 수를 의미하는 array 형성

    int digit_count = number_to_process;
    while (digit_count != 0)
    {
        digit_count /= 10;
        number_of_digits += 1;
    }

    int power = number_of_digits - 1;
    while (power >= 0)
    {
        result = number_to_process / pow(10, power);
        result = result % 10;
        // cout << result << endl;
        digits[result] += 1;
        power -= 1;
    }

    for (int i = 0; i < 10; i++)
        // cout << digits[i] << endl;
        if (digits[i] > occurrence_threshold)
            cout << i << " ";
}


int main() {
    int reply, output;
    unsigned int number_list_to_process;
    unsigned int digit, order, threshold;

    do {
        cout << "===========================================" << endl;
        cout << "Choose what to do next:" << endl;
        cout << "1: Occurrence counting" << endl;
        cout << "2: Index finding" << endl;
        cout << "3: Filtering by occurrence" << endl;
        cout << "4: Quit" << endl;
        cin >> reply;

        switch(reply) {
        case 1:
            cout << "Please enter a number (0 to " << UINT_MAX << "):" ;    // uint_max = maximum for unsigned int
            cin >> number_list_to_process;
            cout << "Please enter the digit-of-interest:";
            cin >> digit;
            output = occurrence_counting(number_list_to_process, digit);
            cout << "Digit " << digit << " occurs " << output << " times." << endl;
            break;
        case 2:
            cout << "Please enter a number (0 to " << UINT_MAX << "):" ;
            cin >> number_list_to_process;
            cout << "Please enter the digit-of-interest:";
            cin >> digit;
            cout << "Please enter the order of that digit:";
            cin >> order;
            output = index_finding(number_list_to_process, digit, order);
            switch (order)
            {
            case 1:
                cout << "The " << order << "st" << " occurrence of digit " << digit << " is at " << output << '.' << endl;
                break;
            case 2:
                cout << "The " << order << "nd" << " occurrence of digit " << digit << " is at " << output << '.' << endl;
                break;
            default:
                cout << "The " << order << "th" << " occurrence of digit " << digit << " is at " << output << '.' << endl;
                break;
            }
            
            break;
        case 3:
            cout << "Please enter a number (0 to " << UINT_MAX << "):" ;
            cin >> number_list_to_process;
            cout << "Please enter the occurrence threshold:";
            cin >> threshold;
            cout << "Digits occurs more than " << threshold << " times are: " ;
            filtering_by_occurrence(number_list_to_process, threshold);
            cout << endl;
            break;
        default:
            break;
        }

    } while (reply != 4);

    return 0;
}
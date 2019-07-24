#include <iostream>
#include <vector>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <sstream>
#include <boost/date_time/date_parsing.hpp>

using namespace boost::gregorian;


int main()
{
    date prev(not_a_date_time);
    date cur(not_a_date_time);
    long long ans = 0;
    std::string s;
    std::cin >> s;

    boost::date_time::months_of_year conv[12] = {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

    prev = date(std::stoi(s.substr(0, 4)), conv[std::stoi(s.substr(5, 2)) - 1], std::stoi(s.substr(8, 2)));

    while (std::cin >> s) {
        //cur = from_simple_string(s);
        cur = date(std::stoi(s.substr(0, 4)), conv[std::stoi(s.substr(5, 2)) - 1], std::stoi(s.substr(8, 2)));

        days dur = prev - cur;
        ans += std::abs(dur.days());

        prev = cur;
    }

    std::cout << ans << std::endl;
}


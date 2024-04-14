'''
Jack is always excited about sunday. It is favourite day, when he gets to play all day and goes to
cycling with his friends.
So, every time when the months starts he counts the number of sundays he will get to enjoy.
Considering the month can start with any day, be it Sunday, Monday…. Or so on.
Count the number of Sunday jack will get within n number of days.
Example 1:
Input: mon-> input String denoting the start of the month.
13 -> input integer denoting the number of days from the start of the month.
Output: 2 -> number of days within 13 days.
Explanation:
The month start with mon(Monday). So, the upcoming Sunday will arrive in next 6 days. And then
next Sunday in next 7 days and so on.
Now total number of days are 13. It means 6 days to first Sunday and then remaining 7 days will end
up in another Sunday. Total 2 Sundays may fall within 13 days
'''

mapp = {
    "mon":1,
    "tue":2,
    "wed":3,
    "thu":4,
    "fri":5,
    "sat":6,
    "sun":7
}

day = input()
num_days = int(input())


num_days = num_days - (mapp["sun"] - mapp[day])

if num_days < 0:
    res = 0
else:
    res = 1
    res = res + (num_days//7)
    
print(res)
    
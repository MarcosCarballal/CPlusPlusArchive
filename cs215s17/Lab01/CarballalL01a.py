

ListOfNumbers = []
total = 0
print("Please enter 10 integer values.")
print("Each value should be entered on a separate line:")
for i in range (0,10):
    Number = int(input(''))
    ListOfNumbers.append(Number)
    total += Number
average = total/(len(ListOfNumbers))
print('The values you entered are:')
print(ListOfNumbers)
print ('The total of your values is:',total)
print ('The average of your values is:',average)
print('The sorted values are:')
SortedListOfNumbers = sorted(ListOfNumbers)
print(SortedListOfNumbers)

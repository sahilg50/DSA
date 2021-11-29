test = [['rash', 4, 28], ['vansha', 2, 20],
        ['nikhil', 1, 20], ['akshat', 3, 21]]
test.sort(key=lambda test: test[2])
print(str(test[1]))

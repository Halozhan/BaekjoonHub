text = str(input())
for i in text:
    if i.islower():
        temp = i.upper()
    elif i.isupper():
        temp = i.lower()
    print(temp, end="")

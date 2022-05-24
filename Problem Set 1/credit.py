from cs50 import get_int

while True:
    creditCard = get_int("Type your credit card number: ")
    if creditCard > 0:
        break

numb = 0
count = 0
digits = 0

check = creditCard


while check > 0:
    numb = (int)(numb + (check % 10))
    check = (int)(check / 10)
    digits = digits + 1

    if check > 0:
        value = (2 * (int))

        if value >= 10:
            while value > 0:
                count = (int)(count + ((int)(value % 10)))
                value = value / 10

        else:
            count = count + value

        check = (int)(check / 10)
        digits = digits + 1

checkSum = count + numb

if (checkSum % 10) == 0:
    while creditCard >= 100:
        creditCard = (int)(creditCard / 10)

    if digits == 15:
        if creditCard == 34 or creditCard == 37:
            result = "AMEX"

        else:
            result = "INVALID"

    elif digits == 13:
        if creditCard >= 40 and creditCard < 50:
            result = "VISA"

        else:
            result = "INVALID"

    elif digits == 16:
        if creditCard == 51 or creditCard == 52 or creditCard == 53 or creditCard == 54 or creditCard == 55:
            result = "MASTERCARD"

        elif creditCard >= 40 and creditCard < 50:
            result = "VISA"

        else:
            result = "INVALID"

    else:
        result = "INVALID"

else:
    result = "INVALID"

print(result)
def istwo(n):
    n = int(n)
    if (n - 1) & n == 0:
        return True
    else:
        return False


def control_bit(s, i):
    i = int(i)
    m = ""
    s = s[i-1:]
    for j in range(0, len(s), 2 * i):
        m += s[j:j + i]
    if m.count("1") % 2 == 0:
        return "0"
    else:
        return "1"


def encode():
    print("Введи сообщение сын матери:")
    user_message = list(input())
    mes_len = len(user_message)
    c = 1
    while c <= mes_len:
        if istwo(c):
            user_message.insert(c - 1, "x")
        c += 1
        mes_len = len(user_message)
    user_message = "".join(user_message)
    for i in range(0, len(user_message)):
        if user_message[i] == "x":
            user_message = user_message[:i] + control_bit(user_message, i + 1) + user_message[i + 1:]
    print("Вот твое закодированное сообщение лсный мусор:", user_message)


def decode():
    bits = ""
    c = 0
    print("Ну что чепуха, вводи свое ублюдское сообщение с ошибкой:")
    user_message = input()
    if istwo(len(user_message)):
        user_message = user_message[:-1]
    for i in range(len(user_message)):
        if istwo(i + 1):
            bits += user_message[i]
            user_message = user_message[:i] + "x" + user_message[i + 1:]
    for i in range(0, len(user_message)):
        if user_message[i] == "x":
            user_message = user_message[:i] + control_bit(user_message, i + 1) + user_message[i + 1:]
    i = 0
    while i < len(user_message):
        if user_message[i] != bits[0]:
            c = c + i + 1
        bits = bits[1:]
        i = i * 2 + 1
    for i in range(0, len(user_message)):
        if i == c - 1:
            if user_message[i] == "1":
                user_message = user_message[:i] + "0" + user_message[i + 1:]
            elif user_message[i] == "0":
                user_message = user_message[:i] + "1" + user_message[i + 1:]
    bits = ""
    for i in range(1, len(user_message) + 1):
        if not istwo(i):
            bits += user_message[i - 1]
    print("Ошибка на", c, "бите мусор")
    print("Исходное сообщение клоун:", bits)


# main
print("Пикай:\n1.Закодировать\n2.Декодировать")
pick = int(input())
if pick == 1:
    encode()
elif pick == 2:
    decode()
else:
    print("Пикни нормально некст тайм, ты в муте клоун")

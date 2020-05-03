from cs50 import get_string

text = get_string("Text: ")
letterCount = 0
wordCount = 1
sentenceCount = 0

for i in range(len(text)):
    if ((text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z')):
        letterCount += 1
    elif (text[i] == " "):
        wordCount += 1
    elif (text[i] == '.' or text[i] == '!' or text[i] == '?'):
        sentenceCount += 1

grade = 0.0588 * (100 * float(letterCount / wordCount)) - 0.296 * (100 * float(sentenceCount / wordCount)) - 15.8
if (grade < 16 and grade >= 0):
    print("Grade \n", int(round(grade)))
elif (grade >= 16):
    print("Grade 16+\n")
else:
    print("Before Grade 1\n")

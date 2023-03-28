word = input()
new_word = sorted(list(set(word)))
max_word = None
max_count = 0
for i in new_word:
    if max_count < word.count(i):
        max_word = i
        max_count = word.count(i)

print(max_word)
print(max_count)

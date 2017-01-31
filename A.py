# This file can pass the test if you choose 'PyPy 3'.

inputList = input().split()

if len(inputList) != 2:
  print('Invalid input!')

num1 = int(inputList[0])
num2 = int(inputList[1])
outList = []

for i in range(int(num1 ** 0.5)):
  if num1 % (i+1) == 0:
    outList.append(i+1)

outSize = len(outList)
for j in range(outSize):
  if num1/(outList[outSize - j - 1]) != outList[outSize - j - 1]:
    outList.append(int(num1/(outList[outSize - j - 1])))

if num2 > len(outList) or num2 < 1:
  print(-1)
else:
  print(outList[num2-1])

# This file can pass the test if you choose 'Python 3'.

inputLine = input().split()
pcU = int(inputLine[0])
pcP = int(inputLine[1])
pcUP = int(inputLine[2])

priceList1 = []
priceList2 = []
readSize = int(input())
for i in range(readSize):
  tmpList = input().split()
  if str(tmpList[1]) == 'USB':
    priceList1.append(int(tmpList[0]))
  else:
    priceList2.append(int(tmpList[0]))

uNum = len(priceList1)
pNum = len(priceList2)
priceList1.sort()
priceList2.sort()
price = 0
equip = 0

tmp = min(uNum,pcU)
price += sum(priceList1[0:tmp])
equip += tmp
del priceList1[0:tmp]
uNum -= tmp
pcU -= tmp

tmp = min(pNum,pcP)
price += sum(priceList2[0:tmp])
equip += tmp
del priceList2[0:tmp]
pNum -= tmp
pcP -= tmp

priceList = priceList1
priceList.extend(priceList2)
priceList.sort()
fNum = len(priceList)
tmp = min(fNum,pcUP)
price += sum(priceList[0:tmp])
equip += tmp

print(str(equip)+' '+str(price))

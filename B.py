inputLine = input().split()
pcU = int(inputLine[0])
pcP = int(inputLine[1])
pcUP = int(inputLine[2])

mouseList = []
priceList = []
readSize = int(input())
for i in range(readSize):
  tmpList = input().split()
  priceList.append(int(tmpList[0]))
  if str(tmpList[1]) == 'USB':
    mouseList.append(1)
  else:
    mouseList.append(2)

price = 0
equip = 0
for i in range(readSize):
  tmpPrice = min(priceList)
  minPos = priceList.index(tmpPrice)
  del priceList[minPos]
  tmpType = mouseList[minPos]
  del mouseList[minPos]
  if tmpType == 1:
    if pcU > 0:
      pcU -= 1
      price += tmpPrice
      equip += 1
    else:
      if pcUP > 0:
        pcUP -= 1
        price += tmpPrice
        equip += 1
  else:
    if pcP > 0:
      pcP -= 1
      price += tmpPrice
      equip += 1
    else:
      if pcUP > 0:
        pcUP -= 1
        price += tmpPrice
        equip += 1

print(str(equip)+' '+str(price))

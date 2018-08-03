from collections import defaultdict
from queue import PriorityQueue

def getGCD(num1, num2):
    if num1 > num2:
        smallerNum = num2
    else:
        smallerNum = num1
    for i in range(1, smallerNum+1):
        if((num1 % i == 0) and (num2 % i == 0)):
            gcd = i
    #print(gcd)
    return gcd

def printOutput_ToFile(results,filename):

    fout = open(filename,"w+")

    for testCase, result in enumerate(results):
        tempRes = " ".join(result)
        fout.write("Case #" + str(testCase+1)+ ": " + tempRes + "\n")
        #print("Case #" + str(testCase+1)+ ": " + tempRes)

    fout.close()
    return

def getInput_FromFile(filename):

    fin = open(filename,"r")
    cnt = 0
    testCases = {}
    newTestCase = False
    isAttrList = False
    attrCount = 0
    tempAttrList = []

    for line in fin:
        line = line.strip()

        if (cnt==0):
            cnt+=1
            newTestCase = True
            isAttrList = False
            continue

        if (newTestCase):
            items = line.split()
            items = [int(x) for x in items]
            attrCount = int(items[0])
            newTestCase = False
            isAttrList = True
            testCases[cnt] = [items]
            continue

        if (isAttrList):
            if (attrCount==1):
                newTestCase = True
                isAttrList = False
                tempAttrList.append(line)
                testCases[cnt].append(tempAttrList)
                tempAttrList = []
                cnt+=1
                continue

            else:
                attrCount-=1
                tempAttrList.append(line)

    fin.close()
    return testCases

def tourist(n,k,v,attr):

    result = []
    q1 = PriorityQueue()
    q2 = PriorityQueue()

    for key in range(len(attr)):
        q1.put(key)

    factor = int(int(n*k)/getGCD(n, k))
    iterCount = (int(factor/k))
    totalIter = v%iterCount

    if (totalIter == 0):
        totalIter = iterCount

    done = True
    i = 0

    while(i < totalIter):
        attrCount = 0
        result = []

        if(done):
            while((not q1.empty()) and attrCount<k):
                curr = q1.get()
                result.append(curr)

                attrCount+=1
                q2.put(curr)

            if(q1.empty()):
                done=False

            if((not done) and attrCount<k):
                while(attrCount<k):
                    curr = q2.get()
                    result.append(curr)

                    attrCount+=1
                    q1.put(curr)

        elif(not done):

            while((not q2.empty()) and attrCount<k):

                curr = q2.get()
                result.append(curr)

                attrCount+=1
                q1.put(curr)

            if(q2.empty()):
                done=True

            if(done and attrCount<k):

                while(attrCount<k):
                    curr = q1.get()
                    result.append(curr)

                    attrCount+=1
                    q2.put(curr)
        i+=1

    result = sorted(result)
    return [attr[key] for key in result]

if __name__ =='__main__':

    testCases_Table = getInput_FromFile("tourist.txt")
    results = []

    testCases = []
    for key in testCases_Table.keys():
        #print(testCases_Table[key])
        testCases.append(testCases_Table[key])

    for tn, testCase in enumerate(testCases):
        N = testCase[0][0]
        K = testCase[0][1]
        V = testCase[0][2]
        A = testCase[1]
        tempRes = tourist(N,K,V,A)
        results.append(tempRes)

    #for result in results:
    #    print(result)

    printOutput_ToFile(results,"output.txt")

def updateTailPos(xH,yH,xT,yT, pairsT) -> tuple:
    if xH == xT and yH == yT:
        return xT,yT

    if yH == yT:
        if xH>xT and (xH-xT)>1:
            xT+=1
        elif xT>xH and (xT-xH)>1:
            xT-=1
    elif xH == xT:
        if yH>yT and (yH-yT)>1:
            yT+=1
        elif yT>yH and (yT-yH)>1:
            yT-=1
    elif abs(xH-xT)>1 or abs(yH-yT)>1:
        if xH>xT and yH>yT:
            xT+=1
            yT+=1
        elif xH>xT and yH<yT:
            xT+=1
            yT-=1 
        elif xH<xT and yH<yT:
            xT-=1
            yT-=1 
        elif xH<xT and yH>yT:
            xT-=1
            yT+=1

    pairsT.append((xT,yT))

    return xT,yT


def calculateScoreEx1(input_file_name):    

    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
        x = 0
        y = 0
        xT = 0
        yT = 0 

        pairs = []
        pairsT = []
        pairs.append((x, y))
        pairsT.append((xT, yT))
        for ln in lines:
            ln = ln.split()
                
           
            if ln[0] == 'R':
                for p in range(0,int(ln[1])):
                    x += 1
                    pairs.append((x, y))
                    xT,yT= updateTailPos(x,y,xT,yT, pairsT)
                
            elif ln[0] == 'L':
                for p in range(0,int(ln[1])):
                    x -= 1
                    pairs.append((x, y))
                    xT,yT= updateTailPos(x,y,xT,yT, pairsT)
               
            elif ln[0] == 'U':
                for p in range(0,int(ln[1])):
                    y += 1
                    pairs.append((x, y))
                    xT,yT= updateTailPos(x,y,xT,yT, pairsT)
               
            elif ln[0] == 'D':
                for p in range(0,int(ln[1])):
                    y -= 1
                    pairs.append((x, y))
                    xT,yT= updateTailPos(x,y,xT,yT, pairsT)
                        
    return len(set(pairsT))


def calculateScoreEx2(input_file_name):
    return 0

if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")
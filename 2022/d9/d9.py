def updateTailPos(tH,tT, pairsT) -> tuple:

    xH=tH[0]
    yH=tH[1]
    xT=tT[0]
    yT=tT[1]

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
                    xT,yT= updateTailPos((x, y),(xT,yT), pairsT)
                
            elif ln[0] == 'L':
                for p in range(0,int(ln[1])):
                    x -= 1
                    pairs.append((x, y))
                    xT,yT= updateTailPos((x, y),(xT,yT), pairsT)
               
            elif ln[0] == 'U':
                for p in range(0,int(ln[1])):
                    y += 1
                    pairs.append((x, y))
                    xT,yT= updateTailPos((x, y),(xT,yT), pairsT)
               
            elif ln[0] == 'D':
                for p in range(0,int(ln[1])):
                    y -= 1
                    pairs.append((x, y))
                    xT,yT= updateTailPos((x, y),(xT,yT), pairsT)
                        
    return len(set(pairsT))


def calculateScoreEx2(input_file_name):
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
        x = 0
        y = 0

        knots_points=[]#list of visited coordinates
        knots_xy = []#current coordinates
        num_knots=10
       
        for k in range(0,num_knots):
            alist=[]
            knots_points.append(alist)
            knots_xy.append((0, 0))
       

        for ln in lines:
            ln = ln.split()                
           
            if ln[0] == 'R':
                for p in range(0,int(ln[1])):
                    x=knots_xy[0][0]#move the head
                    x+=1
                    knots_xy[0] = (x,knots_xy[0][1])
                    for k in range(0,num_knots-1):
                        knots_points[k].append(knots_xy[k])
                        knots_xy[k+1]= updateTailPos(knots_xy[k], knots_xy[k+1], knots_points[k+1])
                
            elif ln[0] == 'L':
                for p in range(0,int(ln[1])):
                    x=knots_xy[0][0]#move the head
                    x-=1
                    knots_xy[0] = (x,knots_xy[0][1])
                    for k in range(0,num_knots-1):
                        knots_points[k].append(knots_xy[k])
                        knots_xy[k+1]= updateTailPos(knots_xy[k], knots_xy[k+1], knots_points[k+1])
               
            elif ln[0] == 'U':
                for p in range(0,int(ln[1])):
                    y=knots_xy[0][1]#move the head
                    y+=1
                    knots_xy[0] = (knots_xy[0][0],y)
                    for k in range(0,num_knots-1):
                        knots_points[k].append(knots_xy[k])
                        knots_xy[k+1]= updateTailPos(knots_xy[k], knots_xy[k+1], knots_points[k+1])
               
            elif ln[0] == 'D':
                for p in range(0,int(ln[1])):
                    y=knots_xy[0][1]#move the head
                    y-=1
                    knots_xy[0] = (knots_xy[0][0],y)
                    for k in range(0,num_knots-1):
                        knots_points[k].append(knots_xy[k])
                        knots_xy[k+1]= updateTailPos(knots_xy[k], knots_xy[k+1], knots_points[k+1])
                        
    return len(set(knots_points[-1]))

if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")
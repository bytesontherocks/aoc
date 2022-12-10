


def getX(cycle):
    return 0

def calculateScoreEx1(input_file_name):    
    reg = []
    x=1
    cycle=0
    reg.append(x)
    with open(input_file_name, "r") as f:
        lines = f.read().splitlines()
        for ln in lines:
            ln = ln.split()
            cycle+=1

            if ln[0] == "addx":
                reg.append(x)
                cycle+=1
                reg.append(x)
                x += int(ln[1])
            else:
                reg.append(x)
                
    th=[20,60,100,140,180,220]
    sum=0
    for val in th:
        sum+=reg[val]*val
        print(f"reg: {reg[val]} val: {val}")

    print(sum)
        
    return 0
# cycle cmd     Val
# 0               1
# 1     noop      1
# 2     addx 3    1
# 3               1
# 4     addx -5   4


def calculateScoreEx2(input_file_name):    
    f = open(input_file_name, "r")
    lines = f.readlines()  
    return 0

if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")
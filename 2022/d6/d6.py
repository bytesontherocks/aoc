

def calculateScoreEx1(input_file_name):    
    f = open(input_file_name, "r")
    lines = f.readlines()
    input = lines[0]

    num_it = 4
    for ch in range(0,len(input)-4):
        marker = input[ch] + input[ch+1] +input[ch+2] + input[ch+3]
        if len(set(marker)) == 4:
            print(marker)
            break
        num_it += 1
        
    print(num_it)
    
    score = 0


    return score

def calculateScoreEx2(input_file_name):    
    score = 0
   

    return score

        
if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")
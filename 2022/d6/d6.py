def getMarkerPosition(input, marker_size):
    num_it = marker_size
    for ch in range(0,len(input)-marker_size):
        marker = ""
        for x in range(0,marker_size):
            marker += input[ch + x]

        if len(set(marker)) == marker_size:
            print(marker)
            break
        num_it += 1

    return num_it

def calculateScoreEx1(input_file_name):    
    f = open(input_file_name, "r")
    lines = f.readlines()
    return getMarkerPosition(lines[0], 4)

def calculateScoreEx2(input_file_name):    
    f = open(input_file_name, "r")
    lines = f.readlines()  
    return getMarkerPosition(lines[0], 14)

if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")
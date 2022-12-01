# rock paper scissors
# A     B       C
# X     Y       Z

# A > C / Z
# B > A / X
# C > B / Y
abc = {"A" : 1, "B" : 2, "C" : 3}
xyz = {"X" : 1, "Y" : 2, "Z" : 3}
score_from_xyz = {"A X" : 3, "A Y" : 6,"A Z" : 0,"B X" : 0, "B Y" : 3, "B Z" : 6, "C X" : 6, "C Y" : 0, "C Z" : 3}
to_lose = {"A" : "Z", "B" : "X", "C" : "Y"} 
to_win = {"A" : "Y", "B" : "Z", "C" : "X"} 
to_draw = {"A" : "X", "B" : "Y", "C" : "Z"}

def calculateScoreEx1(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()

    score = 0
    for line in lines:
        line = line.strip('\n')
        our_char = line[len(line)-1]
        score += xyz[our_char] +  score_from_xyz[line]    
    return score

# X lose , Y draw, Z end
def calculateScoreEx2(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()

    score = 0
    for line in lines:
        line = line.strip('\n')
        action_char = line[len(line)-1]
        their_char = line[0]
        our_char = to_draw[their_char] #action_char == 'Y'
        vdl = 3
        if action_char == 'X':
            our_char = to_lose[their_char]
            vdl = 0
        elif action_char == 'Z':
            our_char = to_win[their_char]
            vdl = 6

        score += xyz[our_char] +  vdl
    return score
        
        
if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")
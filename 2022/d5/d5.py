import queue

def calculateScoreEx1(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()

    q = queue.LifoQueue()

    score = 0
    

    return score

def calculateScoreEx2(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()

    score = 0
  

    return score

        
if __name__ == "__main__":
    res1 = calculateScoreEx1("input.txt")
    res2 = calculateScoreEx2("input.txt")
    print(f"ex1: {res1}, ex2: {res2}")
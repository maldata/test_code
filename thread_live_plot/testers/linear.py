#!/usr/bin/python3

def main():
    points = [(1,1), (3,2), (5,-1)]
    for i in range(0, len(points)-1):
        p1 = points[i]
        p2 = points[i+1]
        m = (p2[1] - p1[1]) / (p2[0] - p1[0])
        b = p1[1] - m * p1[0]
        print("y={0}x+{1}".format(m,b))

if __name__ == "__main__":
    main()

    

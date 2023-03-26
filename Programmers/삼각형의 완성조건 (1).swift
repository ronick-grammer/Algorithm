//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120889
import Foundation

func solution(_ sides:[Int]) -> Int {
    
    var sides = sides
    sides.sort()
    
    let result = (sides[0] + sides[1] > sides[2]) ? 1 : 2
    
    return result
}

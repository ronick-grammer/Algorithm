//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120899
import Foundation

func solution(_ array:[Int]) -> [Int] {
    
    let max = array.max()!
    let index = array.firstIndex(of: max)!
    
    return [max, index]
}

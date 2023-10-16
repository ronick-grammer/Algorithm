//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/159994
import Foundation

func solution(_ cards1:[String], _ cards2:[String], _ goal:[String]) -> String {
    
    var result = "Yes"
    var cards1Index = 0
    var cards2Index = 0
    
    goal.forEach {
        if cards1.count > cards1Index && $0 == cards1[cards1Index] {
            cards1Index += 1
        } else if cards2.count > cards2Index && $0 == cards2[cards2Index] {
            cards2Index += 1
        } else {
            result = "No"
            return
        }
    }
        
    return result
}

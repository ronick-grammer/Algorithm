//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120904
import Foundation

func solution(_ num:Int, _ k:Int) -> Int {
    var numStr = String(num)
    
    if let index = numStr.firstIndex(of: Character(String(k))) {
        return numStr.distance(from: numStr.startIndex, to: index) + 1
    } else {
        return  -1
    }
}

//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120909
import Foundation

func solution(_ n:Int) -> Int {
    var t = Int(sqrt(Double(n)))
    return (t * t == n) ? 1 : 2
}

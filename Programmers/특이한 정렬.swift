//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120880
import Foundation

func solution(_ numlist:[Int], _ n:Int) -> [Int] {
    
    return numlist.sorted {
        let aDistance = abs($0.distance(to: n))
        let bDistance = abs($1.distance(to: n))
        
        if aDistance == bDistance {
            return $0 > $1
        } else {
            return aDistance < bDistance
        }
    }
}

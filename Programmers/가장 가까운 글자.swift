//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/142086
import Foundation

func solution(_ s:String) -> [Int] {
    
    var indexes = [String: Int]()
    var result = [Int]()
    
    for (index, char) in s.enumerated() {
        if indexes.contains(where: { $0.key == String(char) }) {
            let distance = indexes[String(char)]!.distance(to: index)
            result.append(distance)
        } else {
            result.append(-1)
        }
        
        indexes.updateValue(index, forKey: String(char))
    }
    
    return result
}

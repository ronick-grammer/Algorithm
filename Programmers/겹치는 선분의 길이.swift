// problem link: https://school.programmers.co.kr/learn/courses/30/lessons/120876
import Foundation

func solution(_ lines:[[Int]]) -> Int {
    
    // -100 ~ 100 == 0 ~ 200 위 범위이다
    var flattenLines: [Int] = Array(repeating: 0, count: 200)
    
    lines.forEach {
        // 겹치는 선분 갯수만 새야 하므로 ..< 연산을 사용하여 겹치지 않는 부분에 대한 갯수 새어짐에 방지한다
        for i in $0[0] ..< $0[1] {
            flattenLines[i + 100] += 1
        }
    }
    
    return flattenLines.filter { $0 > 1}.count
}

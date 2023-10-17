//problem link: https://school.programmers.co.kr/learn/courses/30/lessons/118666
import Foundation

func validIndex(str: String) -> Int {
    switch str {
    case "RT", "TR": return 0
    case "CF", "FC": return 1
    case "JM", "MJ": return 2
    case "AN", "NA": return 3
    default: return -1
    }
}

func solution(_ survey:[String], _ choices:[Int]) -> String {
    var result: String = .init(repeating: " ", count: 4)
    var scores: [String: (Int, Int)] = [
        "RT": (0, 0),
        "CF": (0, 0),
        "JM": (0, 0),
        "AN": (0, 0)
    ]
    
    for (index, score) in choices.enumerated() {
        var eachScore: (Int , Int)
        
        if (1 ... 3) ~= score {
            eachScore = (4 - score, 0)
        } else if (5 ... 7) ~= score {
            eachScore = (0, (score - 5) + 1)
        } else {
            eachScore = (0, 0)
        }
        
        let reversed = String(survey[index].reversed())
        if scores.contains(where: { $0.key == reversed } ) {
            let first = scores[reversed]!.0
            let second = scores[reversed]!.1
            scores[reversed] = ((first + eachScore.1),(second + eachScore.0))
        } else {
            scores.updateValue((scores[survey[index]]!.0 + eachScore.0, scores[survey[index]]!.1 + eachScore.1), forKey: survey[index])
        }
    }
        
    scores.forEach {
        let index = result.index(result.startIndex, offsetBy: validIndex(str: $0.key))
        var element: String
        if $0.value.0 > $0.value.1 {
            element = String($0.key.first!)
        } else if $0.value.0 < $0.value.1 {
            element = String($0.key.last!)
        } else {
            if $0.key.first! > $0.key.last! {
                element = String($0.key.last!)
            } else {
                element = String($0.key.first!)
            }
        }
        result.replaceSubrange(index ... index, with: element)
    }
    
    return result
}

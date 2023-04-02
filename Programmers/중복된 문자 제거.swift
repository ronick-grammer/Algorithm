import Foundation

func solution(_ my_string:String) -> String {
    
    var result = ""
    my_string.forEach {
        if !result.contains($0) {
            result.append(String($0))
        }
    }
    
    return result
}

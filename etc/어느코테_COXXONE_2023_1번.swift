// 설명: 31일을 한달로 두고 일한 시간에 대한 전체 수당을 구하는 문제
import Foundation

func solution(_ works:[[Int]], _ wage:Int) -> Int {
    // 하루: 24시간(0 ~ 23), 한달: 31일(0~31), 31일이 끝나는 날은 32일 0시
    var timeTable: [[Bool]] = .init(repeating: .init(repeating: false, count: 24), count: 33)
    
    // 일한 시간대를 true 처리
    works.forEach { work in
        var day = work[0]
        var hour = work[1]
        let endDay = work[2]
        var endhour = work[3]

        while !(day == endDay && hour == endhour) {
            timeTable[day][hour] = true
            hour += 1
            if hour >= 24 {
                hour = 0
                day += 1
            }
        }
    }
    
    // 기본 수당
    let regular = timeTable.joined().filter { $0 }.count * wage

    // 초과수당
    let overtime = timeTable.map { day in
        let hours = day.filter({ $0 }).count
        if hours > 8 {
            return Double(hours - 8)
        } else {
            return 0
        }
    }.reduce(0) { $0 + $1 } * (Double(wage) * 0.5)

    // 야간수당
    let night = timeTable.map { day in
        Double(day[22...23].filter { $0 }.count)
    }.reduce(0) { $0 + $1 } * (Double(wage) * 0.5)

    // 주말수당
    var weekend: Double = 0
    [timeTable[6...7], timeTable[13...14], timeTable[20...21], timeTable[28...29]].forEach { weekendDays in
        let weekendHours = weekendDays.map { day in
            Double(day.filter { $0 }.count)
        }.reduce(0) { $0 + $1 }
        weekend += (weekendHours * (Double(wage) * 0.5))
    }

    // 주휴수당
    var week: Double = 0
    [timeTable[1...7], timeTable[8...14], timeTable[15...21]].forEach { weekDays in
        let weekHours = weekDays.map { day in
            Double(day.filter { $0 }.count)
        }.reduce(0) { $0 + $1 }
        week += (weekHours >= 15 ) ? weekHours * (Double(wage) * 0.2) : 0
    }
    
    return Int(regular) + Int(overtime) + Int(night) + Int(weekend) + Int(week)
}
// 답: 934,500, 주휴수당: 102,000
solution([[1, 22, 3, 8], [13, 12, 13, 17], [14, 22, 15, 0]], 15000)

// 답: 300,000, 주휴수당: 40,000
//solution([[1, 8, 1, 13], [5, 18, 6, 9]], 10000)

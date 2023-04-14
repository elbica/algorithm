function getTime(time){
    const splited = time.split(':');
    return 60*60*(+splited[0]) + 60*(+splited[1]) + +splited[2];
}

const MAX = 3_600_666;

function solution(play_time, adv_time, logs) {
    const sums = new Array(MAX).fill(0);
    const playTime = getTime(play_time);
    const advTime = getTime(adv_time);
    
    for(const log of logs){
        let [start, end] = log.split('-');
        start = getTime(start), end = getTime(end);
        sums[start]++, sums[end]--;
    }
    
    for(let i = 1; i<= playTime; i++){
        sums[i] += sums[i-1];
    }
    
    let time = 0, start = 0, end = 1, temp = 0, saveStartTime = 0;
    for(end; end<=advTime; end++) time += sums[end - 1];
    temp = time;
    // console.log({start, end, sum: sums[start], e: sums[end], time})
    
    for(; end<=playTime + 1; end++, start++){
        time = time - sums[start] + sums[end -1];
        if(temp < time){ saveStartTime = start+1; temp = time;}
    }
    
    const hour = ''+Math.floor(saveStartTime / 3600);
    const min = ''+Math.floor((saveStartTime % 3600)/60);
    const sec = ''+saveStartTime % 60;
    var answer = `${hour.length == 1 ? '0'+hour : hour}:${ min.length == 1 ? '0'+min : min}:${sec.length==1 ? '0'+sec : sec}`;
    return answer;
}
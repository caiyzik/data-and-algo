//
// Created by Tiffany Montgomery on 2019-10-05.
//

#pragma once

int divide2(int x){
    //recursive function that returns how many times
    // you need to divide a number by two before getting less than 2
    int y = x/2;
    if (y < 2){
        return 1;
    } else {
        return 1 + divide2(y);
    }
}

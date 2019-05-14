//
//  HashMapUtil.h
//  GraphAL
//
//  Created by Jakub Cichy on 14/05/2019.
//  Copyright © 2019 Jakub Cichy. All rights reserved.
//

#ifndef HashMapUtil_h
#define HashMapUtil_h

class HashMapUtil {
  
public:
    
    static bool isPrime(int number) {
        if(number<2)
            return false;
        for(int i=2; i*i<=number; i++) {
            if(number%i == 0)
                return false;
        }
        return true;
    }
};

#endif /* HashMapUtil_h */

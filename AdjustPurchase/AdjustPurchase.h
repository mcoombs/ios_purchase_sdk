//
//  AdjustPurchase.h
//  AdjustPurchase
//
//  Created by Uglješa Erceg on 13/11/15.
//  Copyright © 2015 adjust GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ADJPCommon.h"
#import "ADJPConfig.h"
#import "ADJPVerificationInfo.h"

/**
 *  @brief  Static class used for In-App-Purchase receipt verification.
 */
@interface AdjustPurchase : NSObject

/**
 *  @brief  Initilisation method which needs adjust app token and environment
 *          which are later bundled in HTTP request to adjust backend server.
 *
 *  @param  config  ADJPConfig object.
 */
+ (void)init:(ADJPConfig *)config;

/**
 *  @brief  Method used to verify In-App-Purchase receipt.
 *
 *  @param  receipt         Apple receipt.
 *  @param  transaction     SKPaymentTransaction object obtained after transaction
 *                          state became SKPaymentTransactionStatePurchased and
 *                          after transaction has been finished.
 *  @param  responseBlock   Block which will get executed once verification info is available.
 */
+ (void)verifyPurchase:(NSData *)receipt
        forTransaction:(id)transaction
     withResponseBlock:(ADJPVerificationAnswerBlock)responseBlock;

@end
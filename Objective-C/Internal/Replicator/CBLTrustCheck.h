//
//  CBLTrustCheck.h
//  CouchbaseLite
//
//  Copyright (c) 2017 Couchbase, Inc All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import <Foundation/Foundation.h>
#import <Security/SecTrust.h>
#import "CBLReplicatorConfiguration.h"

@interface CBLTrustCheck : NSObject

+ (void) setAnchorCerts: (NSArray*)certs
              onlyThese: (BOOL)onlyThese;

- (instancetype) initWithChallenge: (NSURLAuthenticationChallenge*)challenge;

- (instancetype) initWithTrust: (SecTrustRef)trust
                          host: (NSString*)host
                          port: (uint16_t)port;

@property (copy, atomic) NSData* pinnedCertData;

- (NSURLCredential*) checkTrust: (NSError**)outError;

#ifdef COUCHBASE_ENTERPRISE
- (NSURLCredential*) acceptOnlySelfSignedCert: (NSError**)outError;
#endif

@end

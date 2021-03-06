////////////////////////////////////////////////////////////////////////////////
//
//  TYPHOON FRAMEWORK
//  Copyright 2013, Jasper Blues & Contributors
//  All Rights Reserved.
//
//  NOTICE: The authors permit you to use, modify, and distribute this file
//  in accordance with the terms of the license agreement accompanying it.
//
////////////////////////////////////////////////////////////////////////////////



#import <Foundation/Foundation.h>
#import "TyphoonComponentFactory.h"
#import "TyphoonIntrospectiveNSObject.h"
#import "TyphoonRuntimeArguments.h"

@class TyphoonCallStack;

/**
* Encapsulates the methods related to assembling an instance using the Objective-C runtime. This is an internal category - the methods will
* not be required for normal use of Typhoon.
*/
@interface TyphoonComponentFactory (InstanceBuilder)

- (TyphoonCallStack *)stack;

- (id)buildInstanceWithDefinition:(TyphoonDefinition *)definition args:(TyphoonRuntimeArguments *)args;

- (id)buildSharedInstanceForDefinition:(TyphoonDefinition *)definition args:(TyphoonRuntimeArguments *)args;

- (void)doInjectionEventsOn:(id)instance withDefinition:(TyphoonDefinition *)definition args:(TyphoonRuntimeArguments *)args;

- (NSArray *)allDefinitionsForType:(id)classOrProtocol;

- (TyphoonDefinition *)definitionForType:(id)classOrProtocol;

- (void)injectAssemblyOnInstanceIfTyphoonAware:(id)instance;

- (void)resolveCircularDependency:(NSString *)key args:(TyphoonRuntimeArguments *)args resolvedBlock:(void(^)(BOOL isCircular))resolvedBlock;

@end

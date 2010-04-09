// --- файл singleton.h --

@interface Singleton : NSObject {
}

+(Singleton*) instance;

@end
// -- файл singleton.m --

#import "Singleton.h";

@implementation Singleton

static Singleton *instance_;

static void singleton_remover() {
    [instance_ release];
}

+ (Singleton*)instance {
    @synchronized(self) {
        if( instance_ == nil ) {
            [[self alloc] init];
        }
    }

    return instance_;
}

- (id)init {
    self = [super init];
    instance_ = self;

    atexit(singleton_remover);

    return self;
}

- (void)dealloc {
    [super dealloc];
}
@end
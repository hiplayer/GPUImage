#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreMedia/CoreMedia.h>
#import "GPUImageOpenGLESContext.h"
#import "GPUImageOutput.h"

@interface GPUImageVideoCamera : GPUImageOutput <AVCaptureVideoDataOutputSampleBufferDelegate>
{
    AVCaptureSession *captureSession;
    NSUInteger numberOfFramesCaptured;
    CGFloat totalFrameTimeDuringCapture;
    BOOL runBenchmark;
}

@property(readonly) AVCaptureSession *captureSession;
@property(readwrite, nonatomic) BOOL runBenchmark;

// Initialization and teardown
- (id)initWithSessionPreset:(NSString *)sessionPreset cameraPosition:(AVCaptureDevicePosition)cameraPosition; 

// Manage the camera video stream
- (void)startCameraCapture;
- (void)stopCameraCapture;

// Benchmarking
- (CGFloat)averageFrameDurationDuringCapture;

@end

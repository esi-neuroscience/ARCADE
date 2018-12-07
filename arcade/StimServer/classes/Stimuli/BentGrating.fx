//--------------------------------------------------------------------------------------
// File: Grating_barBend.fx
// Pixel Shader
//--------------------------------------------------------------------------------------
//
// Grating with harmonic (cosine) bars instead of straight lines.
// change is locked to a particular phase of the grating cycle
// change has a linear increase in amplitude to max and back to zero


cbuffer PS_ANIMATION : register (b1)
{
    float  framesElapsed : packoffset(c0.x);
};

cbuffer PS_CONSTANT_BUFFER : register (b0)
{

    // grating position 
    float2 center       : packoffset(c0.x);
    float  width         : packoffset(c0.z);
    float  height        : packoffset(c0.w);   

    // grating parameters
    float  radius       : packoffset(c1.x); // param 1  "pixels"
    float  cycle        : packoffset(c1.y); // param 2  "pixels"
    float  direction    : packoffset(c1.z); // param 3  "degrees"
    float  speed        : packoffset(c1.w); // param 4  "pixels"
    float  smoothR      : packoffset(c2.x); // param 5  

    // change parameters
    float  changeAmplitude     : packoffset(c2.y); // param 6  "pixels"
    float  changeFrameDuration : packoffset(c2.z); // param 7  "frames"
    float  changePhase         : packoffset(c2.w); // param 8  "change phase"
    // float  frameOffset         : packoffset(c3.x);  // params 9-10

};

cbuffer PS_COLOR_BUFFER : register (b2)
{
    float4 color0   : packoffset(c0.x); // color 1
    float4 color1   : packoffset(c1.x); // color 2
    float4 color2   : packoffset(c2.x); // color 3 
    float4 color3   : packoffset(c3.x); // color 4
};

float4 PSmain( float4 Pos : SV_POSITION ) : SV_Target
{
    float frameOffset = 0.0f;
    if (distance(center, Pos.xy) > radius) discard;
    static const float pi = 3.141592654;

    // 2.0f = sinewave, values < 2.0f produce artifact
    float R = (smoothR ? smoothR: 2.0f);

    // grating direction 
    float2 p;
    sincos(radians(-1.0f*direction), p.y, p.x);

    // this pixel position relative pixelshader center 
    float2 pixPos = center-Pos.xy;

    // smoothstep(min, max, x)
    // Returns 0 if x is less than min; 1 if x is greater than max; 
    // otherwise, a value between 0 and 1 if x is in the range [min, max].
    float changeStartFrame = 0.0f;
    float changeEndFrame   = changeFrameDuration;

    // framesElapsed starts at 1, not zero 
    float currentFrame = frameOffset + framesElapsed-1;

    float A = clamp((currentFrame - changeStartFrame)/(changeEndFrame - changeStartFrame), 0.0, 1.0);
    float modAmp = changeAmplitude * abs(2.0f*(A-floor(A+0.5f))); // sawtooth wave

    float period         = radius*4.0f;   // modulation is half of cosine cycle   (relative to radius)
    //float period         = radius*2.0f; // modulation is a full cosine cycle    (relative to radius)
    //float period         = radius;      // modulation is two full cosine cycles (relative to radius)

    // shift pixel position in x direction dependent on y 
    float cosineShift = modAmp * cos(2.0f*pi*dot(pixPos,float2(p.y,-p.x))/period);

    // framesElapsed starts at 1, not 0
    //float tempShift = speed*(framesElapsed-1);
    //float tempShift = speed*framesElapsed; // should move through zero 
    float tempShift = speed*currentFrame; // bug fix 12.12.2016

    // calculate sinewave 
    float sineWave = sin( (tempShift + cosineShift + dot(pixPos,p))/cycle *(2.0f*pi) + radians(changePhase));
    // make it  "squarewave" like
    // float bright   = (width+height*0.0f)+(pow(abs(sineWave), 2.0f/R) * sign(sineWave) + 1.0f) / 2.0f;
    float bright = sineWave + 0.5;

    // if colored, implement color via alpha blending  
    return color0*(float4)(1.0f-bright) + color1*(float4)bright;
}

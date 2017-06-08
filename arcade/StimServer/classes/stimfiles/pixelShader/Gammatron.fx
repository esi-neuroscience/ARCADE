//--------------------------------------------------------------------------------------
// File: Grating.fx
// Pixel Shader
//--------------------------------------------------------------------------------------

extern float width  = 166.0f;
extern float height = 166.0f;

cbuffer PS_ANIMATION : register (b1)
{
    float  speed : packoffset(c0.x);
};

cbuffer PS_CONSTANT_BUFFER : register (b0)
{
    float2 center       : packoffset(c0.x);
    float  orientation	: packoffset(c0.z);
    float  cycle        : packoffset(c0.w);
};

//     vvvvvvv function name must match the file name
float4 Grating( float4 Pos : SV_POSITION ) : SV_Target
{
    //if (distance((float2) center, Pos) < 20.0f) discard;
    if (distance((float2) center, Pos) > 83.0f) discard;
    static const float pi = 3.141592654;
    float ori = orientation*(pi/180.0f);

    float gtron = sqrt((center.y-Pos.y)*(center.y-Pos.y) + (Pos.x-center.x)*(Pos.x-center.x))*2.0f*pi;

    float bright = (sin( speed + gtron*(2.0f*pi)/(cycle ? cycle : 75.0f)) + 1.0f)/2.0f;
    return float4( bright, bright, bright, width/height );
}

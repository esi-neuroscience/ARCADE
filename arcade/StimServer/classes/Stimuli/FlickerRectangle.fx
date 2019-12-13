//--------------------------------------------------------------------------------------
// File: Flicker.fx
// Pixel Shader
//--------------------------------------------------------------------------------------

cbuffer PS_ANIMATION : register (b1)
{
    float  frame : packoffset(c0.x);
};

cbuffer PS_CONSTANT_BUFFER : register (b0)
{
    float2 center        : packoffset(c0.x);
    float  width         : packoffset(c0.z);
    float  height        : packoffset(c0.w);
    float  period        : packoffset(c1.x);
};

cbuffer PS_COLOR_BUFFER : register (b2)
{
    float4 color0   : packoffset(c0.x); // color 1
    float4 color1   : packoffset(c1.x); // color 2

};


float4 PSmain( float4 Pos : SV_POSITION ) : SV_Target
{
    static const float pi = 3.141592654;
    // float onTime = uint(onTime ? onTime: 30.0f);
    // if ((uint(frame) % (2*uint(onTime))) > (uint(onTime)-1))
    if ( uint(floor(frame / period)) & 1 )

    {
        return color0;
    }
    else
    {
        return color1;
    };
}

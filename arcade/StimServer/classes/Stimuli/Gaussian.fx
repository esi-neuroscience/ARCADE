//--------------------------------------------------------------------------------------
// File: Gaussian.fx
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
    float  sx : packoffset(c1.x); // standard deviation in px
    float  sy : packoffset(c1.y); // standard deviation in px
    float  angle : packoffset(c1.z); // rotation in degree
};

cbuffer PS_COLOR_BUFFER : register (b2)
{
    float4 color0   : packoffset(c0.x); // color 1
};


float4 PSmain( float4 Pos : SV_POSITION ) : SV_Target
{    
    float theta = -radians(angle);
    float rx = (center.x-Pos.x);
    float ry = (center.y-Pos.y);
    float sxx = pow(sx,2.0f);
    float syy = pow(sy,2.0f);
    float a = pow(cos(theta),2.0f)/(2.0f*sxx) + pow(sin(theta),2.0f)/(2.0f*syy);
    float b = -sin(2.0f*theta)/(4.0f*sxx) + sin(2.0f*theta)/(4.0f*syy);
    float c = pow(sin(theta),2.0f)/(2.0f*sxx) + pow(cos(theta),2.0f)/(2.0f*syy);

    float bright = exp(-( a*pow(rx,2.0f) - 2.0f*b*rx*ry + c*pow(ry,2.0f) ));
    float4 g = color0;
    g[3] = bright;

    return g;
}

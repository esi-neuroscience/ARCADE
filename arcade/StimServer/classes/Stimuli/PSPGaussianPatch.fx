Texture2D<float4> Texture	: register(t0);
sampler TexSampler : register(s0);
struct INPUT {
    float4 Pos        : SV_POSITION;
    float4 Color      : COLOR;		// ignore for this kind of shader
    float2 TexCoord   : TEXCOORD;
};

cbuffer PS_ANIMATION : register (b1)
{
    float  time : packoffset(c0.x);
};

cbuffer PS_CONSTANT_BUFFER : register (b0)
{
    float2 center	: packoffset(c0.x);
    float  width	: packoffset(c0.z);
    float  height	: packoffset(c0.w);
    float2 shift	: packoffset(c1.x);	// params 1-2: shift of gaussian rel. to picture
    float  amplitude    : packoffset(c1.z);	// param 3: amplitude of the gaussian
    float  sigma	: packoffset(c1.w);	// param 4: "std. dev." of the gaussian
    float4 dummy2	: packoffset(c2.x);	// params 5-8
};

float4 PSmain( INPUT input) : SV_Target
{
    if (sigma == 0.0f) return Texture.Sample(TexSampler, input.TexCoord);
    float alpha = 1.0f - amplitude*exp(-pow(distance(center+shift*float2(1.0f,-1.0f), input.Pos.xy), 2) / (2.0f * sigma * sigma));
    return Texture.Sample(TexSampler, input.TexCoord) * float4(1.0f, 1.0f, 1.0f, alpha);
}

function cfg = retrieveConfig

BHVstore = SGLBehaviouralStore.launch;   % behavioural store (for CFG)
cfg = BHVstore.cfg;

end


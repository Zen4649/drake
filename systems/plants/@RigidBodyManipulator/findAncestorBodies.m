function ancestor_bodies = findAncestorBodies(obj, body_index)
%findAncestorBodies    Find indices of ancestors of a body
%   @param body_index index of a rigid body in this RigidBodyManipulator
%   @retval the indices of the parents of the rigid body with index
%   body_index, not including body_index, ordered from closest to most
%   distant ancestor

if (body_index < 1)
  error('body index should be positive')
end

ancestor_bodies = nan(obj.getNumBodies(), 1); % conservative vector size
ancestor_index = 0;

body = obj.getBody(body_index);

while hasParent(body)
  parent_index = body.parent;
  ancestor_index = ancestor_index + 1;
  ancestor_bodies(ancestor_index) = parent_index;
  
  body = obj.getBody(parent_index);
end

ancestor_bodies = ancestor_bodies(1 : ancestor_index);

end

function ret = hasParent(body)
ret = body.parent ~= 0;
end

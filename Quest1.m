load ps.pts

N=ps(1,1);
ps2=sortrows(ps([2:end],:));
tri=delaunay(ps2(:,2),ps2(:,3));
trimesh(tri,ps2(:,2),ps2(:,3),zeros(size(ps2(:,2))));


% Generation d'un fichier d'entiers contenant la triangulation
fictri = 'listri.dat';
[fid, message] = fopen(fictri,'w');
if (fid < 0) error([message,' (fichier ',fictri,')']), end
fprintf(fid,'%d\n',length(tri));
fprintf(fid,'%d %d %d\n',tri');
fclose(fid);
prolog_c([function([int], function(Main, []), [], 
cmp_stmts([
declaration([typedef, struct('anonymous', [struct_decl([int], [Quot]), struct_decl([int], [Rem])])], [Div_t]), 
declaration([typedef, struct('anonymous', [struct_decl([long], [Quot]), struct_decl([long], [Rem])])], [Ldiv_t]), 
declaration([typedef, struct('anonymous', [struct_decl([long, long], [Quot]), struct_decl([long, long], [Rem])])], [Lldiv_t]), 
declaration([typedef, struct('anonymous', [struct_decl([int], [Id]), struct_decl([char], [array_decl(Name, int(50))]), struct_decl_anonymous(struct('anonymous', [struct_decl([int], [Day]), struct_decl([int], [Month]), struct_decl([int], [Year])]))])], [UC_Employee]), 
return_stmt(int(0))

]))
]).
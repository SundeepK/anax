#ifndef TAGCACHE_H_
#define TAGCACHE_H_

#include <unordered_map>
#include <boost/any.hpp>
#include <anax/detail/ClassTypeId.hpp>

namespace anax {

class TagCache {

public:
	TagCache();
	virtual ~TagCache();

	template<typename Tag_type>
	Entity::Id getTagId(const Tag_type& tag) const;

	template<typename Tag_type>
	void putTag(const Tag_type& tag, const Entity::Id);

private:

	std::unordered_map<boost::any, detail::TypeId> m_tagsToUniqueIds;
};

// return -1 if no id is found for tag
template<typename Tag_type>
Entity::Id TagCache::getTagId(const Tag_type& tag) const {
	int tagId = -1;
	auto tagIterator = m_tagsToUniqueIds.find(tag);
	if (tagIterator != m_tagsToUniqueIds.end()) {
		tagId = tagIterator.second;
	}
	return tagId;
}

template<typename Tag_type>
void TagCache::putTag(const Tag_type& tag, const Entity::Id id) {
	m_tagsToUniqueIds[tag] = id;
}

}

#endif /* TAGCACHE_H_ */
